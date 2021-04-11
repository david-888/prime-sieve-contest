
mkdir -p build-android

ecj -d build-android src/main/java/com/zhang/math/*

cd build-android

dx --dex --output=com/zhang/math/prime/CliParameterException.dex com/zhang/math/prime/CliParameterException.class
dx --dex --output=com/zhang/math/prime/WarmupException.dex com/zhang/math/prime/WarmupException.class
dx --dex --output=com/zhang/math/prime/PrimeSieve.dex com/zhang/math/prime/PrimeSieve.class
dx --dex --output=com/zhang/math/prime/PrimeSieveCli.dex com/zhang/math/prime/PrimeSieveCli.class

cd ..

