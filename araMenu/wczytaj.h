void wczytaj(int nrSave){
    std::fstream file;
    std::string line;

    file.open("Saves/a.txt", std::ios::in);

    if(file.good() == false)
    {
        ms_error(84, "Load_From_File/LoadSave/file.good() == false", 1);
        file.close();
    }
    getline(file, line);
    if(line.length() == 0)
    {
        ms_error(101, "Load_From_File/LoadSave/file is broken!!!", 1);
        file.close();
    }
}
