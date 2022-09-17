#include<stdio.h>
float sqr_root(float val){
    float high=val, low=0,mid=0;
    while(low<=high){
        mid=(low+high)/2;
        if(mid*mid==val || (mid*mid>= val-0.005 && mid*mid <= val+0.005) ){
            return mid;
        }
        else if(mid*mid>val){
            high=mid;
        }
        else{
            low=mid;
        }
    }


}
int main(){
    printf("Sqrt of:");
    float val;
    scanf("%f",&val);

    float out= sqr_root(val);
    printf("outcome: %f and value covered: %f",out, out*out);

return 0;
}
