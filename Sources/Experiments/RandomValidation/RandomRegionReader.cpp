#include "RandomRegionReader.h"

SupervisedImage ChoosedRegion::readNextSupervisedImage()const{
	return SupervisedImage(QString(this->image_path.c_str()),QString(this->supervised_path.c_str()));
}


RandomRegionReader::RandomRegionReader(string file){
	this->actualRegion = 0;
	this->Regions.clear();
	int cont = 0;
	FILE *arq = fopen(file.c_str(), "rb");
	char linha[400], linha2[400];
	srand(time(0));
	while(!feof(arq)){
		fgets(linha, 400, arq);
		fgets(linha2, 400, arq);
		if(!feof(arq)){
                SupervisedImage img = SupervisedImage(QString(linha),QString(linha2));
                 int n = rand() % img.getRegions().size();
		 	Regions.push_back(ChoosedRegion(linha,linha2,n));
		}
	}
}

ChoosedRegion:: ChoosedRegion(string i, string s, int rv):image_path(i), supervised_path(s), regionChoosed(rv){
}

bool RandomRegionReader::hasNextRegion()const{
	return (actualRegion<Regions.size())?true:false;
}

ChoosedRegion RandomRegionReader::readNextRegion(){
	return Regions[actualRegion++];
}