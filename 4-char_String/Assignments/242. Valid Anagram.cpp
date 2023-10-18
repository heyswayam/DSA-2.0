class Solution {
public:
// M-1
bool usingSort(string s, string t){
        sort(s.begin(),s.end());
        sort(t.begin(), t.end());
        if(s.compare(t)){
            return false;
        }
        return true;
}
// M-2 O(n)
bool onePointerApproach(string s, string t){
    int map[256]={0};
    for(auto ch: s){
        // int count=0;
        map[ch]++;
        // cout<<"ch: "<<ch<<" map[ch]: "<<map[ch]<<endl;
    }
    for(auto ch: t){
        if(map[ch]==0){
            return false;
        }
        else{
            map[ch]--;
        }
    }
    
    for(auto i: map){
        if(i!=0){
            return false;
        }
    }
    return true;
}
    bool isAnagram(string s, string t) {
        // return usingSort(s,t);
        return onePointerApproach(s,t);
    }
};