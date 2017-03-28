//
//  Urls.swift
//  CTM
//
//  Created by Paul Bryzek on 3/11/17.
//  Copyright © 2017 CTM. All rights reserved.
//

import Foundation

class Urls {

    static let CLINICAL_DOMAIN = "clinicaltm.com/"
    static let HTTPS_PROTOCOL = "https://"
    static let DEFAULT_URL = "https://clinicaltrainingmanager.com/"
    static let HELP_URL = "https://www.google.com/"
    
    static let PARAM_SERVICE_CODE = "serviceCode"
    static let PARAM_SEARCH = "search"
    static let VALUE_SEARCH_CUSTOMERS = "SearchCustomers"
    static let SEARCH_PATH = "service"
    
    static func buildClinicalUrl(keyPref: String) -> String {
        let url = HTTPS_PROTOCOL + keyPref + "." + CLINICAL_DOMAIN
        return url;
    }
    
    static func buildClinicalUrl() -> String {
        let userId = Prefs.getUserIdPref()
        let urlStr = buildClinicalUrl(keyPref: userId)
        
        return urlStr
    }
    
    static func buildSearchUrl() -> String {
        let url = HTTPS_PROTOCOL + "admin." + CLINICAL_DOMAIN + SEARCH_PATH
        return url;
    }
}
