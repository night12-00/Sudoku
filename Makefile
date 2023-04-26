## Dominic-github (https://github.com/Dominic-github)

file = ./build/main
ifdef OS
	RM = del /Q
	RMDIR = rmdir /q /s
	NewBuild = IF exist build ( rmdir /q /s build &&  mkdir build ) ELSE ( mkdir build)
	makeBuild = cmake -S . -B build -G "Unix Makefiles"
	cmakeBuild = cmake --build ./build    
	makeNewGit = IF exist .git ( rmdir /q /s .git &&  git init ) ELSE ( git init) 

else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		RM = rm -rf 
		RMDIR = rm -rf 
		NewBuild  = rm -rf build && mkdir build
		makeBuild = cmake -S . -B build -G "Unix Makefiles"
		cmakeBuild = cmake --build ./build  
		makeNewGit = rm -rf .git && git init
   	  
	endif
	ifeq ($(UNAME_S),Darwin)
		RM = rm -rf 
		RMDIR = rm -rf 
		NewBuild  = rm -rf build && mkdir build
		makeBuild = cmake -S . -B build -G "Unix Makefiles"
		cmakeBuild = cmake --build ./build  
		makeNewGit = rm -rf .git && git init
	endif

	
endif


all: _build

install_min:
	sudo pacman -Sy gcc g++ cmake 

_build:
	$(NewBuild)
	$(makeBuild)

rebuild:
	$(cmakeBuild)

run:
	$(cmakeBuild)
	$(file)

setup:
	$(RM) README.md
	$(makeNewGit)

