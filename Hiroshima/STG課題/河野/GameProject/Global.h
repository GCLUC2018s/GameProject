#pragma once
#include "stdafx.h"
/**
* @file		Global.h
* @brief	ã§í ÉfÅ[É^
**/

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

#define HOLD_UP		CInput::GetState(0, CInput::eHold, CInput::eUp)
#define HOLD_DOWN	CInput::GetState(0, CInput::eHold, CInput::eDown)
#define HOLD_LEFT	CInput::GetState(0, CInput::eHold, CInput::eLeft)
#define HOLD_RIGHT	CInput::GetState(0, CInput::eHold, CInput::eRight)
#define PUSH_C		CInput::GetState(0, CInput::ePush, CInput::eButton3)

#define HOLD_Z CInput::GetState(0, CInput::eHold, CInput::eButton1)
#define HOLD_X CInput::GetState(0, CInput::eHold, CInput::eButton2)
#define HOLD_R CInput::GetState(0, CInput::eHold, CInput::eButton3)
#define HOLD_V CInput::GetState(0, CInput::eHold, CInput::eButton4)
#define HOLD_Q CInput::GetState(0, CInput::eHold, CInput::eButton7)
#define HOLD_E CInput::GetState(0, CInput::eHold, CInput::eButton8)
#define HOLD_ML CInput::GetState(0, CInput::eHold, CInput::eMouseL)

#define PULL_ML CInput::GetState(0, CInput::ePull, CInput::eMouseL)

#define PUSH_Z CInput::GetState(0, CInput::ePush, CInput::eButton1)
#define PUSH_X CInput::GetState(0, CInput::ePush, CInput::eButton2)
#define PUSH_C CInput::GetState(0, CInput::ePush, CInput::eButton3)
#define PUSH_V CInput::GetState(0, CInput::ePush, CInput::eButton4)
#define PUSH_Q CInput::GetState(0, CInput::ePush, CInput::eButton7)
#define PUSH_E CInput::GetState(0, CInput::ePush, CInput::eButton8)
#define PUSH_ENTER CInput::GetState(0, CInput::ePush, CInput::eButton10)
#define PUSH_ML CInput::GetState(0, CInput::ePush, CInput::eMouseL)
#define PUSH_MR CInput::GetState(0, CInput::ePush, CInput::eMouseR)


#define PUSH_LEFT CInput::GetState(0, CInput::ePush, CInput::eLeft)
#define PUSH_RIGHT CInput::GetState(0, CInput::ePush, CInput::eRight)
#define PUSH_UP CInput::GetState(0, CInput::ePush, CInput::eUp)
#define PUSH_DOWN CInput::GetState(0, CInput::ePush, CInput::eDown)

