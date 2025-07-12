export THEOS = /var/theos
ARCHS = arm64
DEBUG = 0
FINALPACKAGE = 1
FOR_RELEASE = 1
IGNORE_WARNINGS = 1
THEOS_PACKAGE_SCHEME = rootless
TARGET = iphone:clang:latest:12.1

include $(THEOS)/makefiles/common.mk

TWEAK_NAME = FF

SECURITY_SRC = $(wildcard Security/*.mm) $(wildcard Security/oxorany/*.cpp)
LOADVIEW_SRC = $(wildcard LoadView/*.mm) $(wildcard LoadView/*.m)
IMGUI_SRC = $(wildcard imgui/*.cpp) $(wildcard imgui/*.mm)

$(TWEAK_NAME)_FRAMEWORKS =  UIKit Foundation Security QuartzCore CoreGraphics CoreText  AVFoundation Accelerate GLKit SystemConfiguration GameController

$(TWEAK_NAME)_CCFLAGS = -std=c++11 -fno-rtti -fno-exceptions -DNDEBUG -Wall -Wno-deprecated-declarations -Wno-unused-variable -Wno-unused-value -Wno-unused-function -fvisibility=hidden

$(TWEAK_NAME)_CFLAGS = -fobjc-arc -Wall -Wno-deprecated-declarations -Wno-unused-variable -Wno-unused-value -Wno-unused-function -fvisibility=hidden


ifeq ($(IGNORE_WARNINGS),1)
  $(TWEAK_NAME)_CFLAGS += -w
  $(TWEAK_NAME)_CCFLAGS += -w
endif

$(TWEAK_NAME)_FILES = ImGuiDrawView.mm $(SECURITY_SRC) $(LOADVIEW_SRC) $(IMGUI_SRC) $(wildcard hook/*.c) $(wildcard Hosts/*.m)


include $(THEOS_MAKE_PATH)/tweak.mk