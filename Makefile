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
		-o ./wasm-build/clox.js \
		-Iinclude \
		-DTARGET_WASM \
		-s MODULARIZE=1 \
		-s EXPORT_ES6=1 \
		--preload-file input.lox \
		-s EXPORTED_FUNCTIONS=['_wasm_main'] \
		-s EXPORTED_RUNTIME_METHODS=['ccall','cwrap','FS'] \
		-s DEFAULT_LIBRARY_FUNCS_TO_INCLUDE=[] \
		-s NO_FILESYSTEM=0