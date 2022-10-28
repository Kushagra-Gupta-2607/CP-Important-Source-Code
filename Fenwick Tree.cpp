class FenwickTree{
public:
    
    vector<ll> tree;
    
    FenwickTree(int sz){
        tree.resize(sz+1, 0);
    }
    
    FenwickTree(vector<ll>& values){
        
        int n = values.size()+1;
        tree.resize(n, 0);
        for(ll i = 1; i<n; i++){
            tree[i] = values[i-1];
        }
        
        for(ll i = 1; i<n; ++i){
            ll j = i + lsb(i);
            if(j<n) tree[j]+=tree[i];
        }
        
        values = tree;
    }
    
    ll lsb(ll i){
        return i & (-i);
    }
    
    ll prefixSum(ll i){
        ll sum = 0LL;
        while(i){
            sum+=tree[i];
            i &= ~lsb(i);
        }
        return sum;
    }
    
    ll sum(ll i, ll j){
        return prefixSum(j) - prefixSum(i);
    }
    
    void add(ll i, ll k){
        while(i<tree.size()){
            tree[i]+=k;
            i += lsb(i);
        }
    }
    
    void set(ll i, ll k){
        ll prev = sum(i, i+1);
        add(i, k-prev);
    }
    
};
