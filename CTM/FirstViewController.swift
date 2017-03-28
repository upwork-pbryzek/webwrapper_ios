//
//  FirstViewController.swift
//  CTM
//
//  Created by Paul Bryzek on 3/11/17.
//  Copyright © 2017 CTM. All rights reserved.
//

import UIKit

class FirstViewController: UIViewController, UIAlertViewDelegate, UIWebViewDelegate, UserIdPopupDelegate {

    var lastUserId = ""
    
    @IBOutlet weak var webview: UIWebView!
    
    @IBAction func editClick(_ sender: Any) {
        self.launchUserIdPopup()
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.tabBarController?.tabBar.isHidden = true
        
        initWebview()
        
        let userId = Prefs.getUserIdPref()
        
        guard !userId.isEmpty else {
            self.launchUserIdPopup()
            return
        }
        
        loadWebviewByUserId()
    }
    
    func loadWebviewByUserId() {
        let userId = Prefs.getUserIdPref()
        
        //Or if the userId is the same as previously
        if(userId == lastUserId) {
            return;
        }
        
        let urlStr = Urls.buildClinicalUrl()
        self.completeLoadAction(urlString: urlStr) { code in
            if(code >= 200 && code < 300) {
                self.loadClinicalWebview()
            } else {
                self.showUrlErrorDialog()
            }
        }
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
    }
    
    func initWebview() {
        webview.delegate = self;
        webview.backgroundColor = UIColor.clear
    }
    
    func loadHelpWebview() {
        loadWebviewUrl(urlString:Urls.HELP_URL)
    }
    
    func loadClinicalWebview() {
        let urlStr = Urls.buildClinicalUrl()
        loadWebviewUrl(urlString:urlStr)
    }
    
    func loadWebviewUrl(urlString:String) {
        if let url = URL(string: urlString) {
            let request = URLRequest(url: url)
            webview.loadRequest(request)
        }
    }
    
    func showUrlErrorDialog() {
        let urlStr = Urls.buildClinicalUrl()
        let errMsg = "The url entered is unreachable: " + urlStr + "\n"
        let alert = UIAlertController(title: "Error", message: errMsg, preferredStyle: UIAlertControllerStyle.alert)
        
        alert.addAction(UIAlertAction(title: "Ok", style: .default, handler: { (action: UIAlertAction!) in
            self.launchUserIdPopup()
        }))
        
        present(alert, animated: true, completion: nil)
    }
    
    func launchUserIdPopup() {
        let storyboard = UIStoryboard(name: "Main", bundle: nil)
        let vc = storyboard.instantiateViewController(withIdentifier: "UserIdPopup") as! UserIdPopup
        vc.delegate = self
            
        self.showDetailViewController(vc, sender: self)
    }
    
    func loadHelpUrl() {
        loadWebviewUrl(urlString:Urls.HELP_URL)
    }
    
    func completeLoadAction(urlString:String, completion: @escaping (Int) -> ()) {
        let url = URL(string:urlString.trimmingCharacters(in: .whitespaces))
        let request = URLRequest(url: url!)
        let task = URLSession.shared.dataTask(with: request) { data, response, error in
            if(response == nil || error != nil) {
                completion(0)
                return
            }
            
            let httpStatus = response as? HTTPURLResponse
            let httpStatusCode:Int = (httpStatus?.statusCode)!
            
            completion(httpStatusCode)
        }
        task.resume()
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
}

