dictionary = {
    "key1": {"type": "string", "description": "Name"},
    "key2": {"type": "integer", "description": "age"}
}


def add_variable(var_name, var_type, desc):
    dictionary[var_name] = {"type": var_type, "description": desc}


def update(var_name, key, value):
    if var_name in dictionary:
        dictionary[var_name][key] = value
    else:
        print("Error")
