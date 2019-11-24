#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	  ofSetFrameRate(60);
  	ofSetWindowTitle("openFrameworks");

  	ofBackground(239);
    ofNoFill();
    ofSetColor(0);
  	ofSetLineWidth(1.5);

    ofSetCircleResolution(100);
    ofEnableSmoothing();

//  	this->font.loadFont("fonts/Kazesawa-Bold.ttf", 400, true, true, true);
//  	this->mesh.setMode(OF_PRIMITIVE_LINES);
}

//--------------------------------------------------------------
void ofApp::update(){
  ofSeedRandom(39);
  std::stringstream strm;
  strm << "fps: " << ofGetFrameRate();
  ofSetWindowTitle(strm.str());
}

//--------------------------------------------------------------
void ofApp::draw() {
  int reps = 12;
  float xCenter = ofGetWidth() / 2;
  float yCenter = ofGetHeight() / 2;
  float d1 = calcDistance();

  for(int i=0; i<reps; i++)
  {
    float d2 = sqrt(3) * d1 / 2;
    ofDrawCircle(xCenter, yCenter, d1);
    ofDrawTriangle( xCenter, yCenter - d1,
                    xCenter + d2, yCenter + d1/2,
                    xCenter - d2, yCenter + d1/2);
    d1 /= 2;
  }
  if(ofGetFrameNum() < 80)
  {
    img.grabScreen(0, 0 , ofGetWidth(), ofGetHeight());
    std::stringstream strm;
    strm << "screenshot" << (10000 + ofGetFrameNum()) << ".png";
    img.save(strm.str());
  }
  //https://openframeworks.cc/learning/02_graphics/how_to_screenshot/
  // https://hamelot.io/visualization/using-ffmpeg-to-convert-a-set-of-images-into-a-video/
  // ffmpeg -r 60 -f image2 -s 720x720 -i screenshot100%02d.png -vcodec libx264 -crf 25 -filter_complex "loop=loop=5:size=80:start=0" -pix_fmt yuv420p test.mp4
}

float ofApp::calcDistance()
{
  float d00 = ofGetWidth();
  double d01 = 80.0;
  float d02 = d00 * std::pow(2, ((double)(ofGetFrameNum()%(int)d01))/d01);

  return d02;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
