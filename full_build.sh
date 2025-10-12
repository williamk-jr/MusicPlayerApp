source "build.sh"

(
  cp -a ./build/bin/* ../rootfs_overlay/usr/bin;
  cd ../buildroot;
  make;
)