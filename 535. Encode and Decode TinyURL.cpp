//
// Created by yxr on 2018/7/30.
//
int autoIncrement = 1;
map<string,int> dictionary;
string encodeTable = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

string getStringFromAutoIncrement(int aHashValue){
    string basic = "https://";
    while(aHashValue!=0){
        int reminder = aHashValue % 62;
        basic += encodeTable[reminder];
        aHashValue /= 62;
    }
    return basic;
}

int getAutoIncrementFromString(string aShortUrl){
    string basic(aShortUrl);
    basic.erase(0,8);   //remove "https://"
    int hashValue = 0;
    float index = 0;
    for(int i=0; i<basic.size();i++){
        size_t loc = encodeTable.find(basic[i]);
        hashValue += loc*pow(62,index);
        index++;
    }
    return hashValue;
}

// Encodes a URL to a shortened URL.
string encode(string longUrl) {
    auto iter = dictionary.find(longUrl);
    int hashValue = 0;
    if(iter == dictionary.end()){
        dictionary.insert(pair<string,int> (longUrl,autoIncrement) );
        hashValue = autoIncrement;
        autoIncrement++;
    }
    else{
        hashValue = iter->second;
    }
    string encoded = getStringFromAutoIncrement(hashValue);  //change hashValue to string;
    return encoded;
}

// Decodes a shortened URL to its original URL.
string decode(string shortUrl) {
    int hashValue = getAutoIncrementFromString(shortUrl);
    for(auto& iter : dictionary){
        if(iter.second == hashValue){
            return iter.first;
        }
    }
    return "";
}
