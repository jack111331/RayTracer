cmake_minimum_required(VERSION 3.6)

project(ray_tracing)
set(CMAKE_CXX_STANDARD 11)

include_directories("./include")

set(RAYTRACE_SOURCE)
set(RAYTRACE_HEADER)

list(APPEND RAYTRACE_SOURCE
		Vector.cpp
		Ray.cpp
		Sphere.cpp
		HitableList.cpp
		Lambertian.cpp
		Metal.cpp
		Dielectric.cpp
		Camera.cpp
		Utility.cpp
		main.cpp
		)

list(APPEND RAYTRACE_HEADER
		include/Vector.h
		include/Ray.h
		include/Hitable.h
		include/Sphere.h
		include/HitableList.h
		include/Material.h
		include/Lambertian.h
		include/Metal.h
		include/Dielectric.h
		include/Camera.h
		include/Utility.h
		)

set(all_code_files
		${RAYTRACE_HEADER}
		${RAYTRACE_SOURCE}
		)

add_executable(ray_tracing ${all_code_files})
