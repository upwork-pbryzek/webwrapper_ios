//
//  Prefs.swift
//  CTM
//
//  Created by Paul Bryzek on 3/11/17.
//  Copyright © 2017 CTM. All rights reserved.
//

import Foundation

class Prefs {
    
    static let KEY_ID = "userID"
    
    static func setUserIdPref(userId: String) -> Void {
        let defaults = UserDefaults.standard
        defaults.set(userId, forKey: KEY_ID)
    }
    
    static func getUserIdPref() -> String {
        let preferences = UserDefaults.standard
        
        if preferences.object(forKey: KEY_ID) == nil {
            //  Doesn't exist
            return ""
        } else {
            let userId = preferences.object(forKey: KEY_ID)
            return userId as! String
        }
    }
    
}
