type JSONValue = null | boolean | number | string | JSONValue[] | { [key: string]: JSONValue };
type Fn = (...args: JSONValue[]) => void

function cancellable(fn: Fn, args: JSONValue[], t: number): Function {
    fn.apply(null,args)
    const timeId = setInterval(() => fn.apply(null,args), t);
    return () => clearInterval(timeId)
};
