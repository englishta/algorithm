import pathlib
import json

p_nb = pathlib.Path("../path/to/notebook/")

# 全てのセルから条件に一致するセルの番号をreturn
def identify_cell(sentence, cells, cell_type='markdown'):
    for i, _cell in enumerate(cells):
        if _cell['cell_type'] == cell_type and _cell['source'][0] == sentence:
            _cell_num = i
            break
    return _cell_num

for _nb in p_nb.glob("*ipynb"):
    with open(_nb, "r") as f:
        nb = json.load(f)
        cells = nb["cells"]

    # identify cell
    _cn = identify_cell(sentence="## 問1\n", cells=cells)
    ans_cell = cells[_cn + 1]

    score = 0
    try:
        result = ans_cell["outputs"][0]["text"][0]
        if result == "Hello World!":
            score += 1
    except:
        pass

    if score == 2:
        _cn = identify_cell(sentence="##評価\n", cells = cells)

        # score cellの上書き
        cells[_cn + 1] = {'cell_type': 'code',
                        'execution_count': None,
                        'metadata': {},
                        'outputs': [],
                        'source': [str(2)]}       
        # 解答用のipynbに上書き
        json.dump(nb, _nb.open("w"))


