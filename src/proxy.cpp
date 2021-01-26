#include "design_pattern.h"

#include <iostream>
#include <string>

using namespace std;

class Image
{
public:
    Image(){}
    virtual void Draw() = 0;
};


class RealImage : public Image
{
public:
    RealImage(string file_name_);
    bool LoadImage(string file_name_);
    void Draw();

private:
    string file_name;
};

RealImage::RealImage(string file_name_)
{
    this->file_name = file_name_;
}

bool RealImage::LoadImage(string file_name_)
{
    this->file_name = file_name_;
}

void RealImage::Draw()
{
    cout << "Draw " << file_name << endl;
}


class ProxyImage : public Image
{
public:
    RealImage* realImage = NULL;

    ProxyImage(string file_name_);
    void Draw();

private:
    string file_name;
};

ProxyImage::ProxyImage(string file_name_)
{
    file_name = file_name_;
}

void ProxyImage::Draw(){
    if(realImage == NULL){
        cout << "Loading picture" << endl;
        realImage = new RealImage(file_name);
    }
    realImage->Draw();
}


void ProxyPatternTest()
{
    Image* image = new ProxyImage("proxy.jpg");
 
    
    image->Draw(); 
    cout << endl ;
    
    image->Draw();  

    return;
}