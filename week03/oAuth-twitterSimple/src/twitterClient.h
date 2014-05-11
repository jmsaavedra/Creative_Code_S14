//
//  twitterClient.h
//  example-twitter
//
//  Created by Joseph Saavedra on 2/18/14.
//
//

#pragma once

#include "ofMain.h"
#include "ofxOAuth.h"

class twitterClient: public ofxOAuth{
    
public:
    
    twitterClient();
//    virtual ~twitterClient(){
//        
//    }
    
    void setup(const string& consumerKey, const string& consumerSecret);
    
    string exampleSearch(string msg);
    
    string exampleUpdateStatusMethod(string msg);
    
    string exampleUpdateStatusWithPhotoMethod(string msg, string imgpath);    
};