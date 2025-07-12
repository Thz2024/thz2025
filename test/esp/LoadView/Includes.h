#include <MetalKit/MetalKit.h>
#include <Metal/Metal.h>
#include <iostream>
#include <UIKit/UIKit.h>
#include <vector>
#import "pthread.h"
#include <array>
#import <os/log.h>
#import "pthread.h"
#include <cmath>
#include <deque>
#include <vector>
#include <fstream>
#include <algorithm>
#define UIColorFromHex(hexColor) [UIColor colorWithRed:((float)((hexColor & 0xFF0000) >> 16))/255.0 green:((float)((hexColor & 0xFF00) >> 8))/255.0 blue:((float)(hexColor & 0xFF))/255.0 alpha:1.0]

#import "ImGuiDrawView.h"
#import "LoadView.h"
#import "FTNotificationIndicator.h"
#import "../imgui/imgui.h"
#import "../imgui/imgui_internal.h"
#import "../imgui/imgui_impl_metal.h"
#include "Security/Obfuscate.h"

#define kWidth  [UIScreen mainScreen].bounds.size.width
#define kHeight [UIScreen mainScreen].bounds.size.height
#define kScale [UIScreen mainScreen].scale

extern MenuInteraction* menuTouchView;
extern UIButton* InvisibleMenuButton;
extern UIButton* VisibleMenuButton;
extern UITextField* hideRecordTextfield;
extern UIView* hideRecordView;