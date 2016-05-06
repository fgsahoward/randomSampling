GCC=g++
srcDir=src
objDir=obj

FLAGS=-std=c++11 -g

objDir:
	if [[ ! -d "${objDir}" ]]; then mkdir ${objDir}; fi;

directoryReader.o: ${srcDir}/directoryReader.h ${srcDir}/directoryReader.cc objDir
	$(GCC) ${FLAGS} -o ${objDir}/directoryReader.o -c ${srcDir}/directoryReader.cc

randomFileReader.o: ${srcDir}/randomFileReader.h ${srcDir}/randomFileReader.cc objDir
	$(GCC) ${FLAGS} -o ${objDir}/randomFileReader.o -c ${srcDir}/randomFileReader.cc

randomDirectorySampler.o: ${srcDir}/randomDirectorySampler.h ${srcDir}/randomDirectorySampler.cc objDir
	$(GCC) ${FLAGS} -o ${objDir}/randomDirectorySampler.o -c ${srcDir}/randomDirectorySampler.cc

asciiFormatter.o: ${srcDir}/asciiFormatter.h ${srcDir}/asciiFormatter.cc objDir
	$(GCC) ${FLAGS} -o ${objDir}/asciiFormatter.o -c ${srcDir}/asciiFormatter.cc

scrumMasterPicker: directoryReader.o randomFileReader.o randomDirectorySampler.o scrumMasterPicker.cc objDir
	$(GCC) ${FLAGS} -o scrumMasterPicker -I./${srcDir} scrumMasterPicker.cc ${objDir}/directoryReader.o ${objDir}/randomFileReader.o ${objDir}/randomDirectorySampler.o

randomGenerator: directoryReader.o randomFileReader.o randomDirectorySampler.o asciiFormatter.o randomGenerator.cc objDir
	$(GCC) ${FLAGS} -o randomGenerator -I./${srcDir} randomGenerator.cc ${objDir}/directoryReader.o ${objDir}/randomFileReader.o ${objDir}/randomDirectorySampler.o ${objDir}/asciiFormatter.o 

clean:
	rm -f ${objDir}/*.o randomGenerator scrumMasterPicker
	rmdir ${objDir}
