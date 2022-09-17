#include<stdio.h>
float find_cube_root(float n){
    float low=0,high=n,mid,val=n;
    float consider=0.005;
    while(low<high){
        mid=(low+high)/2;
        float z=mid*mid*mid;
        if(z==val || (z>=val-0.005 && z<=val+0.005)){
            return mid;
        }
        else if(z>val){
            high=mid;
        }
        else{
            low=mid;
        }
    }

}
int main(){
    float n;
    printf("n?");
    scanf("%f",&n);
    printf("Cube root of %f is %f\n",n,find_cube_root(n));
return 0;
}
