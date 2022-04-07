//
//  TurnEvaluator.cpp
//  Project7
//
//  Created by Howard Stahl on 6/2/21.
//  Copyright © 2021 Howard Stahl. All rights reserved.
//

#include "TurnEvaluator.h"

namespace cs31
{

TurnEvaluator::TurnEvaluator( Player human, Player computer )
{
    mHumanTotal = human.getRunningTotal();
    mComputerTotal = computer.getRunningTotal();
    mComputerPriorRunningTotal = computer.getPriorRunningTotal();
}

// TODO: complete evaluateTurn( )
// based on the player totals saved by the constructor call,
// determine which possibility has occurred
TurnEvaluator::POSSIBILITIES TurnEvaluator::evaluateTurn( ) const
{
    if(mHumanTotal == mComputerTotal && mHumanTotal == 21 && mComputerTotal == 21 ){
    POSSIBILITIES result = BOTHHAVEBLACKJACK;
    return( result );
    }
    
    else if(mHumanTotal == mComputerTotal ){
    POSSIBILITIES result = NOONEWON;
    return( result );
    }
    else if(mHumanTotal == 21 || mComputerTotal == 21){
        if(mHumanTotal == 21){
            POSSIBILITIES result = HUMANBLACKJACK;
            return result;
        }
        else{
            POSSIBILITIES result = COMPUTERBLACKJACK;
            return result;
        }
    }
    else if( mHumanTotal > 21){
        POSSIBILITIES result = HUMANBUSTED;
        return( result );
    }
    else if( mComputerTotal > 21){
        POSSIBILITIES result = COMPUTERBUSTED;
        return( result );
    }
    
    else if(mHumanTotal > mComputerTotal){
        POSSIBILITIES result = HUMANWON;
        return( result );
    }
    else if(mHumanTotal < mComputerTotal ){
        POSSIBILITIES result = COMPUTERWON;
        return( result );
    }
    
    POSSIBILITIES result = NOONEWON;
    return( result );
    
}

// should the computer keep playing?
bool TurnEvaluator::determineComputerStrategy() const
{
    bool result = true;
    // if human busted, don't bust yourself
    if (mHumanTotal > 21)
        result = false;
    // stop if the computer has won!
    if (mComputerPriorRunningTotal > mHumanTotal)
        result = false;
    // stop once you 17 or more
    if (mComputerTotal > 17)
        result = false;
    return( result );

}

}
