function checkIfInstanceOf(obj: any, classFunction: any): boolean {
    if (obj == null || obj == undefined || typeof classFunction !== 'function') return false

    let proto = Object(obj)
    while (proto != null) {
        if (proto === classFunction.prototype) return true
        proto = Object.getPrototypeOf(proto)
    }
    return false
};
