all: clean cmake

clean:
	rm -rf build
	mkdir build

cmake:
	pushd build/ && \
	cmake .. && \
	cmake --build . && \
	popd