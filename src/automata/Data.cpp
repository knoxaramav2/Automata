#include "Data.hpp"

options::options()
{
	debug=false;
	godmode=false;
}


player::player(string name)
{
	this->name=name;
	id=0;//replace with FNV_1a
	money=0;
	reputation=0;
}


bool saveGame(string fileName, registry&reg)
{
	ofstream out("saves/"+fileName);
	if (!out)
		return false;
	
	//begin registry
	out<<"{\"registry\":[\n";
	out<<"\t{\"players\":[\n";
	for (unsigned x=0; x<reg.players.size(); ++x)
	{
		out<<"\t\t{\"name:\""<<reg.players[x].name<<"\",\n";
		out<<"\t\t\"id:\""<<reg.players[x].id<<"\",\n";
		out<<"\t\t\"money:\""<<reg.players[x].money<<"\",\n";
		out<<"\t\t\"reputation:\""<<reg.players[x].reputation<<"}"<<(x+1<reg.players.size()?",":"")<<"\"\n";
	}
	out<<"\t]}"<<'\n';//end players
	out<<"]}\n";//end registry
		
	
	out.close();
	return true;
}


bool createNewGame(string saveFile, registry&reg)
{
reg.players.push_back(saveFile);


return saveGame(saveFile+".txt", reg);
}

//add window registry, all-in-one update/render order
