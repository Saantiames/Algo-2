def cambios(j, C):
    # Caso base: monto 0 -> solución vacía
    if j == 0:
        return []

    # Caso base: conjunto vacío pero j > 0 -> no hay solución
    if not C:
        return None  # No hay solución

    # Tomamos un elemento de C (sin destruir C original)
    C_aux = list(C)  
    e = C_aux.pop()

    # Opción 1: no usar e
    sin_e = cambios(j, C_aux)

    # Opción 2: usar e (si e <= j), permitiendo reusar e
    con_e = None
    if e <= j:
        sub_sol = cambios(j - e, C)
        if sub_sol is not None:
            con_e = sub_sol + [e]

    # Ahora elegimos la mejor (menor cardinalidad)
    if con_e is None and sin_e is None:
        return None
    elif con_e is None:
        return sin_e
    elif sin_e is None:
        return con_e
    else:
        # Elegimos el conjunto más pequeño
        if len(con_e) < len(sin_e):
            return con_e
        else:
            return sin_e

monto = [68,74,75,83,88,89]
monedas = {15,23,29}
           
for e in monto:
    print(e, ":", cambios(e,monedas))
