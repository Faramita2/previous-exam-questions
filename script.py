import os

def merge_quizes(source_folder, output_file):
    """
    合并指定文件夹下各年份子文件夹中的 quizes.txt 文件到一个文件中。
    
    :param source_folder: 包含年份子文件夹的根文件夹路径
    :param output_file: 合并后的输出文件路径
    """
    # 打开输出文件以写入模式
    with open(output_file, 'w', encoding='utf-8') as outfile:
        # 遍历根文件夹下的所有子文件夹（假设子文件夹名称为年份）
        for year_folder in sorted(os.listdir(source_folder)):
            year_path = os.path.join(source_folder, year_folder)
            
            # 确保是文件夹且包含 quizes.txt 文件
            if os.path.isdir(year_path):
                quiz_file_path = os.path.join(year_path, 'quizes.txt')
                if os.path.isfile(quiz_file_path):
                    # 写入年份标记
                    outfile.write(f"===== Year: {year_folder} =====\n")
                    
                    # 读取 quizes.txt 文件内容并写入输出文件
                    with open(quiz_file_path, 'r', encoding='utf-8') as quiz_file:
                        outfile.write(quiz_file.read())
                    
                    # 添加分隔符以便区分不同年份的内容
                    outfile.write("\n\n")  # 可根据需要调整分隔符格式

    print(f"合并完成！结果已保存到 {output_file}")

# 示例用法
if __name__ == "__main__":
    # 指定包含年份文件夹的根目录
    source_directory = "."  # 替换为实际路径
    # 指定合并后的输出文件路径
    output_filepath = "./merged_quizes.txt"  # 替换为实际路径
    
    # 调用函数进行合并
    merge_quizes(source_directory, output_filepath)