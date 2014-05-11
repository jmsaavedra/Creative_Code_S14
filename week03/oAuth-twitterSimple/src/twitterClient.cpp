//
//  twitterClient.cpp
//  example-twitter
//
//  Created by Joseph Saavedra on 2/18/14.
//
//

#include "twitterClient.h"


twitterClient::twitterClient(){

}

void twitterClient::setup(const string& consumerKey, const string& consumerSecret) {
    
    ofxOAuth::setup("https://api.twitter.com", consumerKey, consumerSecret);
}

// Once setup is called, authenticated calls can be made.
// This method is just an example of whatyour calls might look like.
// http://api.twitter.com/

string twitterClient::exampleSearch(string msg) {
    
    return get("/1.1/search/tweets.json?q="+msg);
}

// This method is an example of posting an status to twitter.
string twitterClient::exampleUpdateStatusMethod(string msg) {
    
    return post("/1.1/statuses/update.json","status="+msg);
}

// This method is an example of posting a status with img attachment to twitter
string twitterClient::exampleUpdateStatusWithPhotoMethod(string msg, string imgpath) {
    
    return postfile_multipartdata("/1.1/statuses/update_with_media.json","status="+msg,"media[]",imgpath);
}