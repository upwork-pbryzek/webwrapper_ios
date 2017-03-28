//
//  UserIdPopup.swift
//  CTM
//
//  Created by Paul Bryzek on 3/20/17.
//  Copyright © 2017 CTM. All rights reserved.
//

import UIKit

protocol UserIdPopupDelegate: class {
    func loadHelpUrl()
    func loadWebviewByUserId()
}

class UserIdPopup: UIViewController, UITableViewDataSource, UITableViewDelegate {
    
    static let TEXTFIELD_USERID = 100
    
    var searchObjs: [SearchObj] = []
    
    weak var delegate: UserIdPopupDelegate? = nil
    
    @IBOutlet weak var popupView: UIView!
    @IBOutlet weak var userIdTxt: UITextField!
    @IBOutlet weak var cancelBtn: UIButton!
    @IBOutlet weak var okBtn: UIButton!
    @IBOutlet weak var helpBtn: UIButton!
    @IBOutlet weak var titleLbl: UILabel!
    @IBOutlet weak var div: UIView!
    @IBOutlet weak var searchTable: UITableView!
    
    @IBAction func cancelClick(_ sender: Any) {
        dismiss(animated: true, completion: nil)
    }
    
    @IBAction func helpClick(_ sender: Any) {
        delegate?.loadHelpUrl()
        dismiss(animated: true, completion: nil)
    }
    
    @IBAction func okClick(_ textField: Any) {
        let userId = userIdTxt.text!
        Prefs.setUserIdPref(userId: userId)
        
        delegate?.loadWebviewByUserId()
        dismiss(animated: true, completion: nil)
    }
    
    func textFieldDidChange(_ textField: UITextField) {
        // By tag
        if textField.tag == UserIdPopup.TEXTFIELD_USERID  {
            guard let userText = textField.text else {
                return
            }
            
            let numChars = userText.characters.count
            
            if (numChars > 0 && (numChars % 3 == 0)) {
                doSearchAPI(searchTerm: userText)
            }
        }
    }
    
    func showSearchErrorDialog(err:String) {
        let urlStr = Urls.buildSearchUrl()
        let errMsg = "The url entered is unreachable: " + urlStr + "\n" + err
        let alert = UIAlertController(title: "Error", message: errMsg, preferredStyle: UIAlertControllerStyle.alert)
        
        alert.addAction(UIAlertAction(title: "Ok", style: .default, handler: { (action: UIAlertAction!) in
        }))
        
        present(alert, animated: true, completion: nil)
    }
    
    func doSearchAPI(searchTerm:String) {
        let searchUrl = Urls.buildSearchUrl()
        
        weak var weakSelf = self
        
        Just.post(
            searchUrl,
            json: [Urls.PARAM_SERVICE_CODE: Urls.VALUE_SEARCH_CUSTOMERS, Urls.PARAM_SEARCH:searchTerm]
        ) { r in
            if r.ok {
                guard r.text != nil else {
                    return
                }

                let data = r.text?.data(using: .utf8)!
                if let json = try? JSONSerialization.jsonObject(with: data!) as? [String:Any] {
                
                    let error: Bool = (json!["error"] as? Bool)!
                    if(error != nil && error) {
                        let errMsg = json!["error_message"] as? String
                        
                        NSLog("doSearchAPI error! : " + errMsg!)
                        return
                    }
                    
                    weakSelf?.searchObjs.removeAll()
                    
                    let customers: [[String:Any]] = json!["customers"] as! [[String:Any]]
                    for customer in customers {
                        var searchObj = SearchObj()
                        
                        if let code = customer["code"] as? String{
                            searchObj.code = code
                        }
                        
                        if let name = customer["name"] as? String{
                            searchObj.name = name
                        }
                        
                        if let description = customer["description"] as? String{
                            searchObj.description = description
                        }
                        
                        weakSelf?.searchObjs.append(searchObj)
                    }
                    weakSelf?.reloadSearchTable()
                    
                } else {
                    print("bad json - do some recovery")
                }
                
            } else {
                guard r.error != nil else {
                    return
                }
                
                let urlErr = r.error
                
                weakSelf?.showSearchErrorDialog(err: urlErr as! String)
            }
        }
    }
    
    func reloadSearchTable() {
        DispatchQueue.main.async {
            self.searchTable.reloadData()
        }
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        setBkgdColor()
        
        initUserIdText()
    }
    
    func initUserIdText () {
        userIdTxt.keyboardAppearance = .dark
        userIdTxt.keyboardType = .default
        userIdTxt.autocorrectionType = .default
        userIdTxt.clearButtonMode = .whileEditing
        userIdTxt.addTarget(self, action: #selector(self.textFieldDidChange(_:)), for: .editingChanged)
        userIdTxt.tag = UserIdPopup.TEXTFIELD_USERID
        
        let userId = Prefs.getUserIdPref()
        userIdTxt.placeholder = "User Id"
        guard userId.isEmpty else {
            userIdTxt.text = userId
            return;
        }
    }
    
    func setBkgdColor() {
        let bkgdColor = UIColor(red: 247/255, green: 247/255, blue: 247/255, alpha: 1.00)
        self.popupView.backgroundColor = bkgdColor
        self.userIdTxt.backgroundColor = bkgdColor
        self.cancelBtn.backgroundColor = bkgdColor
        self.okBtn.backgroundColor = bkgdColor
        self.helpBtn.backgroundColor = bkgdColor
        self.titleLbl.backgroundColor = bkgdColor
        
        self.searchTable.backgroundColor = UIColor.white

    }
    
    //////
    //TableView Delegate Methods
    //////
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return searchObjs.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        // Getting the right element
        let searchObj = searchObjs[indexPath.row]
        
        // Reuse a cell
        let cellIdentifier = "SearchCell"
        let cell = tableView.dequeueReusableCell(withIdentifier: cellIdentifier)
            ?? UITableViewCell(style: .subtitle, reuseIdentifier: cellIdentifier)
        
        // Set the strings on the row
        let titleTxt = searchObj.code + " " + searchObj.name
        cell.textLabel?.text = titleTxt
        cell.textLabel?.textColor = UIColor.black
        cell.detailTextLabel?.text = searchObj.description
        cell.detailTextLabel?.textColor = UIColor.black
        
        // Returning the cell
        return cell
    }
    
    func numberOfSections(in tableView: UITableView) -> Int {
        var numOfSections: Int = 0
        if self.searchObjs.count > 0 {
            tableView.separatorStyle = .singleLine
            numOfSections            = 1
            tableView.backgroundView = nil
        } else {
            let noDataLabel: UILabel = UILabel(frame: CGRect(x: 0, y: 0, width: tableView.bounds.size.width, height: tableView.bounds.size.height))
            noDataLabel.text = "No Search Results"
            noDataLabel.textColor = UIColor.black
            noDataLabel.textAlignment = .center
            tableView.backgroundView = noDataLabel
            tableView.separatorStyle = .none
        }
        return numOfSections
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        tableView.deselectRow(at: indexPath, animated: true)
        
        let searchObj: SearchObj = searchObjs[indexPath.row]
        userIdTxt.text = searchObj.code
    }
    
    func tableView(_ tableView: UITableView, willDisplay cell: UITableViewCell, forRowAt indexPath: IndexPath) {
        cell.backgroundColor = UIColor.clear
    }
}
