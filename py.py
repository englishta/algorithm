import pathlib
import json

p_nb = pathlib.Path("../path/to/notebook/")


for _nb in p_nb.glob("*ipynb"):
    with open(_nb, "r") as f:
        nb = json.load(f)
        ells = nb["cells"]

    def identify_cell(sentence, cells, cell_type='markdown'):
    # 全てのセルから条件に一致するセルの番号をreturn
        for i,_cell in enumerate(cells):
            if _cell['cell_type'] == cell_type \
            and _cell['source'][0] == sentence:
                _cell_num = i
                break
        return _cell_num


    # identify cell
    # _cn = identify_cell(sentence="## 問1\n",
    #                     cells=cells)
    # ans_cell = cells[_cn + 1]