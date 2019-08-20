#include<list>
#include<unordered_map>

using namespace std;
//类似跳表的形式 map保存了迭代器
class LRUCache {
private:
    unordered_map<int,list<pair<int,int> >::iterator> mapLRU;
    list<pair<int,int> > cache;
    int cap;
    
public:
    LRUCache(int capacity) {
       // cache.reserve(2*capacity); list 无reserve
        mapLRU.reserve(2*capacity);
        cap=capacity;
    }
    
    int get(int key) {
        if(mapLRU.find(key)!=mapLRU.end()){
            pair<int,int> temp;
            temp=*mapLRU[key];
            cache.erase(mapLRU[key]);
            cache.push_front(temp);
            mapLRU[key]=cache.begin();
            return temp.second;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mapLRU.find(key)!=mapLRU.end()){
            cache.erase(mapLRU[key]);
            cache.push_front(make_pair(key,value));
            mapLRU[key]=cache.begin();
        }else{
            if(cache.size()==cap){
                mapLRU.erase(cache.back().first);
                cache.pop_back();
              }
            cache.push_front(make_pair(key,value));
            mapLRU[key]=cache.begin();     
            
        }
    }
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */