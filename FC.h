/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/* 
 * File:   FC.h
 * Author: dies
 *
 * Created on September 22, 2020, 3:22 PM
 */
#include <string>
#include <iostream>
#include <filesystem>
#include <vector>
#include <fstream>
#include <algorithm>
#pragma once
namespace fs = std::filesystem;

class FC {
public:
    FC():end_of_files_in_base_(false), folder_ctr_(0), base_path_("./"), move_path_("./"){};
    FC(std::string src_path):end_of_files_in_base_(false), folder_ctr_(0), base_path_(src_path), move_path_("./"){};
    FC(std::string src_path, std::string dst_path):end_of_files_in_base_(false), folder_ctr_(0), move_path_(dst_path), base_path_(src_path){};
    ~FC(){};
    
    void FC_increment();
    void main_loop();
    void collect_files_to_move();
    void delete_files();
    void copy_files();
    void create_folder_by_ctr();
    
private:
    bool end_of_files_in_base_;
    int folder_ctr_;
    std::string base_path_;
    std::string move_path_;
    std::string sub_dir_move_path_;
    std::vector<std::string> files_to_move_;
    std::vector<std::string> files_already_moved_;
};


