//
//  SearchObj.swift
//  CTM
//
//  Created by Paul Bryzek on 3/20/17.
//  Copyright © 2017 CTM. All rights reserved.
//

import Foundation

struct SearchObj {
    
    var name, code, description: String
    
    init(title: String, code: String, description: String) {
        self.name = title
        self.code = code
        self.description = description
    }
    
    init() {
        self.name = ""
        self.code = ""
        self.description = ""
    }

    
}
