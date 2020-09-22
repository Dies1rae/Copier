/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/* 
 * File:   FC.cpp
 * Author: dies
 * 
 * Created on September 22, 2020, 3:22 PM
 */
#include "FC/FC.h"
namespace fs = std::filesystem;

void FC::FC_increment(){
    this->folder_ctr_ += 1;
}

void FC::main_loop(){
    while(!this->end_of_files_in_base_){
        this->create_folder_by_ctr();
        this->collect_files_to_move();
        this->copy_files();
        this->delete_files();
        this->FC_increment();
    }
}

void FC::collect_files_to_move(){
    size_t files_ctr = 0;
    for(auto& file : fs::directory_iterator(this->base_path_)){
        if(!file.is_directory()){       
            std::string tmpF = file.path().string();
            if(std::find(this->files_already_moved_.begin(), this->files_already_moved_.end(), tmpF) == this->files_already_moved_.end()){
                if(files_ctr < 10000){
                    this->files_to_move_.push_back(tmpF);
                    files_ctr++;
                }
            }
        }
    }
    if(this->files_to_move_.empty()){
        this->end_of_files_in_base_ = true;
    }
}

void FC::delete_files(){
    for(const std::string& file : this->files_to_move_){
        this->files_already_moved_.push_back(file);
    }
    this->files_to_move_.clear();
}

void FC::copy_files(){
    for(const std::string& files : this->files_to_move_){
        std::string dst_filename = this->sub_dir_move_path_;
        dst_filename += files.substr(files.find_last_of("/"));
        std::ifstream src(files, std::ios::binary);
        std::ofstream dst(dst_filename, std::ios::binary);
        dst << src.rdbuf();
        src.close();
        dst.close();
    }
}

void FC::create_folder_by_ctr(){
    this->sub_dir_move_path_ = this->move_path_ + std::to_string(this->folder_ctr_);
    fs::create_directories(this->sub_dir_move_path_ );
}
