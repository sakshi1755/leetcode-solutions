class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        //for rectangle 1
        int length=abs(ax1-ax2);
        int width=abs(ay1-ay2);
        int ans=length*width;
        length=abs(bx1-bx2);
        width=abs(by1-by2);
        ans+=length*width;
        length=0;
        width=0;
        if((ay2>=by2 && by2>=ay1) || (by2>=ay2 && ay2>=by1))length=abs(min(by2,ay2)-max(by1,ay1));
        if((ax2>=bx2 && bx2>=ax1) || (bx2>=ax2 && ax2>=bx1))width=abs(min(bx2,ax2)-max(ax1,bx1));
        ans-=length*width;



        return ans;

        
    }
};