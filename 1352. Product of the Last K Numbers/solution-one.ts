class ProductOfNumbers {
    products: number[];
    last_zero: number;

    constructor() {
        this.products = [];
        this.last_zero = -1;
    }

    add(num: number): void {
        if (this.products.length === 0)
            this.products.push(num);

        if (num === 0) {
            this.last_zero = this.products.length;
            this.products.push(num);
            return
        }

        const last: number = this.products[this.products.length - 1];
        this.products.push(last === 0 ? num : last * num);
    }

    getProduct(k: number): number {
        if (this.products.length - 1 - k < this.last_zero) return 0;
        if (this.products.length - 1 - k === this.last_zero) return this.products[this.products.length - 1];
        return this.products[this.products.length - 1] / this.products[this.products.length - 1 - k];
    }
}