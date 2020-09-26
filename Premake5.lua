workspace "EventsProject"

	configurations
	{
		"Debug",
		"Release"
	}
	
	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "EventManager/EventManager.lua"
include "Tester/Tester.lua"

workspace "EventsProject"
	startproject "Tester" 
