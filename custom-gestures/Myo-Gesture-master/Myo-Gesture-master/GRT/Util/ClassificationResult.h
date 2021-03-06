/**
 @file
 @author  Nicholas Gillian <ngillian@media.mit.edu>
 @version 1.0
 
 @brief The ClassificationResult class provides a data structure for storing the results of a classification test.
 */

/*
 GRT MIT License
 Copyright (c) <2012> <Nicholas Gillian, Media Lab, MIT>
 
 Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 and associated documentation files (the "Software"), to deal in the Software without restriction,
 including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all copies or substantial
 portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT
 LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef GRT_CLASSIFICATION_RESULT_HEADER
#define GRT_CLASSIFICATION_RESULT_HEADER
#include "GRTCommon.h"

namespace GRT {

class ClassificationResult{
public:
    /**
     Default Constructor.
     
     Initializes the ClassificationResult instance.
     
     @param UINT classLabel: sets the class label corresponding to this instance. Default value = 0
     @param UINT predictedClassLabel: sets the predicted class label corresponding to this instance. Default value = 0
     @param UINT unprocessedPredictedClassLabel: sets the unprocessed predicted class label corresponding to this instance. Default value = 0
     @param UINT maximumLikelihood: sets the maximum likelihood corresponding to this instance. Default value = 0
     @param VectorDouble classLikelihoods: sets the class likelihoods corresponding to this instance. Default value = empty vector
     @param VectorDouble classDistances: sets the class label corresponding to this instance. Default value = empty vector
     */
    ClassificationResult(UINT classLabel=0,UINT predictedClassLabel=0,UINT unprocessedPredictedClassLabel=0,double maximumLikelihood=0,VectorDouble classLikelihoods=VectorDouble(),VectorDouble classDistances = VectorDouble()){
        this->classLabel = classLabel;
        this->predictedClassLabel = predictedClassLabel;
        this->unprocessedPredictedClassLabel = unprocessedPredictedClassLabel;
        this->maximumLikelihood = maximumLikelihood;
        this->classLikelihoods = classLikelihoods;
        this->classDistances = classDistances;
    }
    
    /**
     Copy Constructor.
     
     Initializes this instance by copying the data from the rhs instance
     
     @param const ClassificationResult &rhs: another instance of the ClassificationResult class
     */
    ClassificationResult(const ClassificationResult &rhs){
        this->classLabel = rhs.classLabel;
        this->predictedClassLabel = rhs.predictedClassLabel;
        this->unprocessedPredictedClassLabel = rhs.unprocessedPredictedClassLabel;
        this->maximumLikelihood = rhs.maximumLikelihood;
        this->classLikelihoods = rhs.classLikelihoods;
        this->classDistances = rhs.classDistances;
    }
    
    /**
     Default Destructor.
     */
    ~ClassificationResult(){
        
    }
    
    /**
     Defines the equals operator
     
     @param const ClassificationResult &rhs: another instance of the ClassificationResult class
     @return returns a pointer to this instace
     */
    ClassificationResult operator=(const ClassificationResult &rhs){
        if( this != &rhs ){
            this->classLabel = rhs.classLabel;
            this->predictedClassLabel = rhs.predictedClassLabel;
            this->unprocessedPredictedClassLabel = rhs.unprocessedPredictedClassLabel;
            this->maximumLikelihood = rhs.maximumLikelihood;
            this->classLikelihoods = rhs.classLikelihoods;
            this->classDistances = rhs.classDistances;
        }
        return *this;
    }
    
    /**
     Returns true if the predicted class label matches the class label.
     
     @return returns true if the predicted class label matches the class label, false otherwise
     */
    bool getCorrectPrediction(){
        return( classLabel == predictedClassLabel);
    }
    
    /**
     Returns the class label corresponding with this classification result.
     
     @return returns the class label
     */
    UINT getClassLabel(){
        return classLabel;
    }
    
    /**
     Returns the predicted class label corresponding with this classification result.
     The predicted class label is the output prediction of your pipeline.
     
     @return returns the predicted class label
     */
    UINT getPredictedClassLabel(){
        return predictedClassLabel;
    }
    
    /**
     Returns the unprocessed predicted class label corresponding with this classification result.
     The unprocessed predicted class label is the output of the classifier in your pipeline.
     
     @return returns the unprocessed predicted class label
     */
    UINT getUnprocessedPredictedClassLabel(){
        return unprocessedPredictedClassLabel;
    }
    
    /**
     Returns the maximum likelihood corresponding with this classification result.
     
     @return returns the maximum likelihood
     */
    double getMaximumLikelihood(){
        return maximumLikelihood;
    }
    
    /**
     Returns the vector of class likelihoods corresponding with this classification result.
     
     @return returns the vector of class likelihoods
     */
    VectorDouble getClassLikelihoods(){
        return classLikelihoods;
    }
    
    /**
     Returns the vector of class distances corresponding with this classification result.
     
     @return returns the vector of class distances
     */
    VectorDouble getClassDistances(){
        return classDistances;
    }
    
    UINT classLabel;
    UINT predictedClassLabel;
    UINT unprocessedPredictedClassLabel;
    double maximumLikelihood;
    VectorDouble classLikelihoods;
    VectorDouble classDistances;
};

}//End of namespace GRT

#endif //GRT_CLASSIFICATION_RESULT_HEADER