from BinaryTrees import Avl


class Tools:
    def tupleDateFactory(self, startYear: int, endYear: int) -> list:
        tupleData = []
        for year in range(startYear, endYear + 1):
            for month in range(1, 13):  # Mês varia de 1 a 12
                if month == 4 or month == 6 or month == 9 or month == 11:
                    daysOfMonths = 30
                elif month == 2:
                    if year % 4 == 0 and (year % 100 != 0 or year % 400 == 0):
                        daysOfMonths = 29
                    else:
                        daysOfMonths = 28
                else:
                    daysOfMonths = 31
                for day in range(1, daysOfMonths + 1):
                    tupleData.append((year, month, day))
        return tupleData


class ExecuteMain:
    def __init__(self, path: str) -> None:
        self.path = path
        self.tools = Tools()
        self.dataTree = Avl()

    def run(self) -> None:
        try:
            print('Carregando árvore de busca binária...')
            with open(self.path, 'r', encoding='utf-8') as file:
                for x in file.readlines():
                    if int(x[21:24]) >= 0:
                        year: int = int(x[:4].strip())
                        month: int = int(x[5:8].strip())
                        day: int = int(x[8:10].strip())
                        n = (year, month, day)
                        self.dataTree.insert(
                            n,
                            nSunspot=int(x[21:24].strip())
                        )
            print('\nCarregamento concluído !\n')
        except Exception as e:
            print(e)
        menu = '''
            Opções:

            1 -> Percurso em-ordem Iterativo.
            2 -> Pecurso pré-ordem Iterativo.
            3 -> Percuroso em-ordem Recusivo.
            4 -> Busca Recursiva.
            5 -> Chave mínima.
            6 -> Chave máxima.
            7 -> Procure um intervalo de chaves.
            0 -> Sair.
            '''
        while True:
            try:
                print(menu)
                op = input('Digite uma opção: ')
                if int(op) == 1:
                    try:
                        self.dataTree.inorderItertive()
                    except Exception as e:
                        raise e
                if int(op) == 2:
                    try:
                        self.dataTree.preorderIterative()
                    except Exception as e:
                        raise e
                if int(op) == 3:
                    try:
                        self.dataTree.inorderRecursive(self.dataTree.node)
                    except Exception as e:
                        raise e
                if int(op) == 4:
                    try:
                        keyY = input('Digite um ano no formato(aaaa): ')
                        keyM = input('Digite um mês no formato(mm): ')
                        keyD = input('Digite um dia no formato(dd): ')
                        print(
                            self.dataTree.searchRecursiveKey(
                                self.dataTree.node, (
                                    int(keyY), int(keyM), int(keyD)
                                )
                            )
                        )
                    except Exception as e:
                        raise e
                if int(op) == 5:
                    try:
                        print(self.dataTree.minimum())
                    except Exception as e:
                        raise e
                if int(op) == 6:
                    try:
                        print(self.dataTree.maximum())
                    except Exception as e:
                        raise e
                if int(op) == 7:
                    try:
                        print('Digite os valores do início...')
                        keyIni = input('Digite um ano no formato(aaaa): ')
                        print('Digite os valores do término...')
                        keyYEnd = input('Digite um ano no formato(aaaa): ')
                        dates = self.tools.tupleDateFactory(
                            int(keyIni), int(keyYEnd)
                        )
                        for tupleDates in dates:
                            print(self.dataTree.searchKey(tupleDates))
                    except Exception as e:
                        raise e
                if int(op) == 0:
                    print('Até logo !')
                    break
            except Exception as e:
                print(e)


if __name__ == '__main__':
    _exec = ExecuteMain('SN_d_tot_V2.0.txt')
    _exec.run()
