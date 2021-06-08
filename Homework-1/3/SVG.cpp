#include "SVG.h"

    SVG::SVG(int _numOfAddedRectangles, Rectangle* _rectangles):
        numOfAddedRectangles(_numOfAddedRectangles),
        rectangles(_rectangles){
        }

    SVG::SVG(const SVG& other){
        this->setRectangles(other.getRectangles());
        this->setNumOfAddedRectangles(other.getNumOfAddedRectangles());
    }

    SVG SVG::operator=(const SVG& other) {
        if (this == &other) {
            return *this;
        } else {
            setRectangles(other.getRectangles());
            setNumOfAddedRectangles(other.getNumOfAddedRectangles());
            return *this;
        }
    }

    SVG::~SVG(){
        delete[] this->rectangles;
    }
    void SVG::setRectangles(const Rectangle* _rectangles) {
        delete[] rectangles;
        this->rectangles = new Rectangle[numOfAddedRectangles + 1];
        for (int i = 0; i < numOfAddedRectangles; i++) {
            rectangles[i] = _rectangles[i];
        }
	}

	Rectangle* SVG::getRectangles() const {
        return this->rectangles;
	}

    void SVG::addRectangle(const Rectangle& rectangle) {
        Rectangle* _rectangles = new Rectangle[numOfAddedRectangles + 1];
        for (int i = 0; i < numOfAddedRectangles; i++) {
            _rectangles[i] = rectangles[i];
        }
        numOfAddedRectangles++;

        rectangles = new Rectangle[numOfAddedRectangles + 1];
        for (int i = 0; i < numOfAddedRectangles - 1; i++) {
            rectangles[i] = _rectangles[i];
        }
        rectangles[numOfAddedRectangles - 1] = rectangle;
        delete[]_rectangles;
    }

    int SVG::getNumOfAddedRectangles()const {
        return this->numOfAddedRectangles;
    }

    void SVG::setNumOfAddedRectangles(int _numOfAddedRectangles) {
        this->numOfAddedRectangles = _numOfAddedRectangles ;
    }
    void SVG::print()const {
        for (int i = 0; i < numOfAddedRectangles; i++){
            cout << i << ": " << endl;
            rectangles[i].print();
        }
    }

    double SVG::FindIndexOfBiggestRectangle() const {
        int index = 0;
        double maxS = 0;
        for(int i = 0; i < numOfAddedRectangles; i++){
            if(maxS < rectangles[i].getS()){
                maxS = rectangles[i].getS();
                index = i;
            }
        }
        cout << "The rectangle with biggest S has index: " << index;
    }
