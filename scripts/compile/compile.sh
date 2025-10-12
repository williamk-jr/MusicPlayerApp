cmake -B build -S . \
  -DCMAKE_C_COMPILER=${CROSS_COMPILE}gcc \
  -DCMAKE_CXX_COMPILER=${CROSS_COMPILE}g++ \
  -DCMAKE_SYSROOT=${SYSROOT} \
  -DCMAKE_C_FLAGS="--sysroot=${SYSROOT}" \
  -DCMAKE_CXX_FLAGS="--sysroot=${SYSROOT}" \
  -DCMAKE_EXE_LINKER_FLAGS="--sysroot=${SYSROOT}" \
  -DCMAKE_SHARED_LINKER_FLAGS="--sysroot=${SYSROOT}" \
  -DCMAKE_MODULE_LINKER_FLAGS="--sysroot=${SYSROOT}" \
  
make -j $(nproc) -C build