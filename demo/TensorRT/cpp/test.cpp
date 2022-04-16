#include <iostream>
#include <opencv2/opencv.hpp>

static const int INPUT_W = 640;
static const int INPUT_H = 640;

cv::Mat static_resize(cv::Mat& img) {
    float r = std::min(INPUT_W / (img.cols*1.0), INPUT_H / (img.rows*1.0));
    // r = std::min(r, 1.0f);
    int unpad_w = r * img.cols;
    int unpad_h = r * img.rows;
    cv::Mat re(unpad_h, unpad_w, CV_8UC3);
    cv::resize(img, re, re.size());
    cv::Mat out(INPUT_H, INPUT_W, CV_8UC3, cv::Scalar(114, 114, 114));
    re.copyTo(out(cv::Rect(0, 0, re.cols, re.rows)));
    cv::imshow("out",out);
    cv::waitKey(0);
    return out;
}

int main(int argc, char **argv){
    std::cout<<"argc = "<<argc <<"  argv ="<<argv[0]<<std::endl;
    cv::Mat img;
    img = cv::imread("/home/fitz/Pictures/bck.jpg");
    

    cv::Mat re_img = static_resize(img);
    return 0;
}