#include "pch.h"
#include "C_DllPathData.h"

using namespace std;

C_DllPathData::C_DllPathData(HINSTANCE i_hDllHandle)
	: m_sDllPath("")
	, m_sDllFilename("")
	, m_sDllDrive("")
	, m_sExePath("")
	, m_sExeFilename("")
{
	char l_czFullDllPathName[1024] = {};
	string l_sFullDllPathName = "";

	//Récupération du path+nom de la dll
	if (GetModuleFileNameA(i_hDllHandle, l_czFullDllPathName, 1023) != 0)
	{
		l_sFullDllPathName = l_czFullDllPathName;

		//On récupère le path et nom séparément
		//Le path contient le '\' ou '/'
		string::size_type l_ulPosLastSlash = l_sFullDllPathName.find_last_of("\\/");
		string::size_type l_ulPosFirstSlash = l_sFullDllPathName.find_first_of("\\/");
		if (l_ulPosLastSlash != string::npos
			&& l_ulPosFirstSlash == 2)
		{
			m_sDllPath = l_sFullDllPathName.substr(0, l_ulPosLastSlash + 1);
			m_sDllFilename = l_sFullDllPathName.substr(l_ulPosLastSlash + 1);
			m_sDllDrive = l_sFullDllPathName.substr(0, 2);
		}
	}

	//RAZ
	char l_czFullExePathName[1024] = {};
	string l_sFullExePathName = "";
	//Récupération de l'exe
	if (GetModuleFileNameA(NULL, l_czFullExePathName, 1023) != 0)
	{
		l_sFullExePathName = l_czFullExePathName;

		//On récupère le path et nom séparément
		//Le path contient le '\'
		string::size_type l_ulPosLastSlash = l_sFullExePathName.find_last_of("\\/");
		if (l_ulPosLastSlash != string::npos)
		{
			m_sExePath = l_sFullExePathName.substr(0, l_ulPosLastSlash + 1);
			m_sExeFilename = l_sFullExePathName.substr(l_ulPosLastSlash + 1);
		}
	}
}

C_DllPathData::~C_DllPathData(void)
{
}

C_DllPathData& C_DllPathData::createInstance(HINSTANCE i_hDllHandle)
{
	static C_DllPathData m_oInstance(i_hDllHandle);
	return m_oInstance;
}

string C_DllPathData::computePath(const std::string& l_sPathToCompute, const bool l_bIsPath)
{
	string l_sReturn = "";

	//On vérifie que le path n'est pas vide
	if (!l_sPathToCompute.empty())
	{
		//Path relatif
		if (l_sPathToCompute[0] == '.')
		{
			//Concaténation du path de la DLL + path relatif
			l_sReturn = m_sDllPath + l_sPathToCompute;
		}
		//Path quasi-absolu
		else if (l_sPathToCompute[0] == '\\')
		{
			//Concaténation du lecteur et du path quasi absolu
			l_sReturn = m_sDllDrive + l_sPathToCompute;
		}
		//Path absolu (x:\xxxxx)
		else if ((l_sPathToCompute.length() > 2) &&
			(l_sPathToCompute[1] == ':') &&
			(l_sPathToCompute[2] == '\\'))
		{
			//Récupération tel quel du path
			l_sReturn = l_sPathToCompute;
		}
		//Autre cas : nom de fichier ou sous-arborescence
		//Ex : "MonFichier.dll" ou "MonPath"
		else
		{
			//On concatène directement
			l_sReturn = m_sDllPath + l_sPathToCompute;
		}

		//Si le on retourne un path, on le complète avec un '\'
		if (l_bIsPath)
		{
			//On fixe un '\' en fin de path s'il y en a pas
			if (l_sReturn[l_sReturn.length() - 1] != '\\')
			{
				l_sReturn += '\\';
			}
		}
		//Sinon on fait rien, car la fin de la chaîne est un nom de fichier
	}

	return l_sReturn;
}

const string& C_DllPathData::getDllPath() const
{
	return m_sDllPath;
}

const string& C_DllPathData::getDllFilename() const
{
	return m_sDllFilename;
}

const string& C_DllPathData::getDllDrive() const
{
	return m_sDllDrive;
}

const std::string& C_DllPathData::getExePath() const
{
	return m_sExePath;
}

const string& C_DllPathData::getExeFilename() const
{
	return m_sExeFilename;
}

string C_DllPathData::getName(const string& i_sFilename)
{
	string l_sReturn;
	string::size_type l_ulPosLastDot = l_ulPosLastDot = i_sFilename.rfind(".");
	if (l_ulPosLastDot != string::npos)
	{
		l_sReturn = i_sFilename.substr(0, l_ulPosLastDot);
	}
	else
		l_sReturn = i_sFilename;

	return l_sReturn;
}

string C_DllPathData::getExt(const string& i_sFilename)
{
	string l_sReturn;
	string::size_type l_ulPosLastDot = i_sFilename.rfind(".");
	if (l_ulPosLastDot != string::npos)
	{
		l_sReturn = i_sFilename.substr(l_ulPosLastDot + 1);
	}

	return l_sReturn;
}
