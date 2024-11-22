all: clean cmake

clean:
	rm -rf build
	mkdir build

cmake:
	pushd build/ && \
	cmake .. && \
	cmake --build . && \
	popd

wasm:
	emcc src/* \
		-Iinclude \
		-DTARGET_WASM \
		-o wasm-build/lox.js \
		-s MODULARIZE=1 \
		-s EXPORT_NAME='LoxModule' \
		-s EXPORTED_RUNTIME_METHODS=['ccall','cwrap','FS'] \
		-s EXPORTED_FUNCTIONS=['_wasm_main'] \
		-s NO_EXIT_RUNTIME=1 \
		-s ENVIRONMENT=web \
		--preload-file input.lox