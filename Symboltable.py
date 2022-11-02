#a program to implement a hash table using python list, using a class name SymblTable for the implementation
class SymbolTable():
   country_code = [('10', 'USA'), ('20', 'India'), ('30', 'Nepal'),('40','Pakistan')]
   def insert(item_list, key, value):
     item_list.append((key, value))
   def search(item_list, key):
     for item in item_list:
        if item[0] == key:
            return item[1]
   print (search(country_code, '20'))
   insert(country_code, '50','Australia')
   insert(country_code, '60','Bangladesh')
   insert(country_code, '70','England')
   insert(country_code,'80','Srilanka')
   insert(country_code,'90','China')
   insert(country_code,'100','Japan')
   print(country_code)
   print(search(country_code, '60'))
   print (search(country_code, '70'))
   country_code.remove(('90','China'))
   print(country_code)