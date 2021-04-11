
cd build-android

dalvikvm -cp com/zhang/math/prime/PrimeSieve.dex:com/zhang/math/prime/PrimeSieveCli.dex:com/zhang/math/prime/CliParameterException.dex:com/zhang/math/prime/WarmupException.dex com.zhang.math.prime.PrimeSieveCli 1000000 100

cd ..

