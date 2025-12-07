#include<stdio.h>
#include "fonction.h"

float power(float a,float b){
    float result=1;
    int i;
    if (b<0){
        b=-b;
        for(i=0;i<b;i++){
            result=result*a;}
            return 1/result;    
    }
  for(i=0;i<b;i++){
    result=result*a;
  } 
  return result;
} 
float factorial(float a){
    int i, F=1;
    if(a==0){return 1; }
    if(a<0){return-1;} //erreur
    for(i=1;i<=a;i++){
        F=F*i;
    } return F;
} 
float square_root(float a){
    int i;
 float g=a/2;
if(a<0){ return -1;}//erreur
for(i=0;i<20;i++){
    g=(g+a/g)/2;
}
return g;
}
float square_root(float a) {
    if (a < 0) return -1; // erreur
    float guess = a / 2;
    for (int i = 0; i < 20; i++) {
        guess = (guess + a / guess) / 2.0;
    }
    return guess;
}
float exponential(float a) {
    float sum = 1.0;
    float term = 1.0;

    for (int i = 1; i <= 20; i++) {
        term *= a / i;
        sum += term;
    }
    return sum;
}
float sine(float a) {
    float term = a;
    float sum = a;

    for (int i = 1; i <= 10; i++) {
        term *= (-1) * a * a / ((2*i)*(2*i+1));
        sum += term;
    }
    return sum;
}
float cosine(float a) {
    float term = 1;
    float sum = 1;

    for (int i = 1; i <= 10; i++) {
        term *= (-1) * a * a / ((2*i-1)*(2*i));
        sum += term;
    }
    return sum;
}
float tangent(float a) {
    float c = cosine(a);
    if (c == 0) return 999999; // erreur
    return sine(a) / c;
} 
float dgr_to_rad(float a){
    return a*3,14/180;
}
float rad_to_dgr(float a){
    return a*180/3,14;
}





