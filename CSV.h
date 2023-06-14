#ifndef GRAPHS__CSV_H_
#define GRAPHS__CSV_H_

#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>

class CSV {
public:
    void addColumn(const std::string& name) {
        columns_.push_back(name);
        column_to_data_[name] = std::vector<std::string>();
    }

    void set(const std::string& column_name, int index, std::string value) {
        if (index > max_index_) {
            max_index_ = index;
        }
        column_to_data_[column_name][index] = value;
    }

    void set(const std::string& column_name, int index, int value) {
        if (index > max_index_) {
            max_index_ = index;
            for (auto& pair: column_to_data_) {
                pair.second.resize(max_index_ + 1);
            }
        }
        column_to_data_[column_name][index] = std::to_string(value);
    }

    void writeToFile(const std::string& path) {
        std::ofstream out(path);
        writeHeader(out);
        writeContent(out);
        out.close();
    }

private:
    int max_index_ = -1;

    std::unordered_map<std::string, std::vector<std::string>> column_to_data_;

    std::vector<std::string> columns_;

    void writeHeader(std::ofstream& out) {
        for (size_t i = 0; i < columns_.size() - 1; ++i) {
            out << columns_[i] << ";";
        }
        out << columns_.back() << "\n";
    }

    void writeContent(std::ofstream& out) {
        for (int i = 0; i < max_index_ + 1; ++i) {
            for (size_t j = 0; j < columns_.size() - 1; ++j) {
                out << column_to_data_[columns_[j]][i] << ";";
            }
            out << column_to_data_[columns_.back()][i] << "\n";
        }
    }
};

#endif  // GRAPHS__CSV_H_
