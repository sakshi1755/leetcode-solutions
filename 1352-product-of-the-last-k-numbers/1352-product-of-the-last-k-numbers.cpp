class ProductOfNumbers {
public:
    vector<int>c;
  //  int i;
    int size;
    int p;
    vector<int>prefix;
    int iszero;
    ProductOfNumbers() {
      //  i=0;
        c={};
        size=0;
        p=1;
        prefix={};
        prefix.push_back(1);
        iszero=-1;

    }
    
    void add(int num) {
        c.push_back(num);
        p*=num;
        size++;
        if(num==0){
            p=1;
            iszero=size;
        }
        prefix.push_back(p);
       
        
    }
    
    int getProduct(int k) {
        long long ans=prefix[size];
        if(iszero>size-k)return 0;
        ans=ans/prefix[size-k];
        return ans;
        
    }
};
//3 0 2 
//2 3 4

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */