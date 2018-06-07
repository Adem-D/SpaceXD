// debugs can be removed

void moveTo(float positionTarget[3]){
    float myState[12];
    float myPos[3];
    float vectorBetween[3];
    float distance;
    api.getMyZRState(myState);
    for (int i = 0; i<3; i++)
        myPos[i] = myState[i];

    mathVecSubtract(vectorBetween, positionTarget, myPos, 3);
    distance = mathVecMagnitude(vectorBetween, 3);
    
  
    //distance can be adjusted to maximise fuel usage and speed
    if (distance>0.2){
        api.setForces(vectorBetween);
        DEBUG(( "Using setForces"));
    }
    else{
        api.setPositionTarget(positionTarget);
        DEBUG(( "Using setPosition"));
    }
}
