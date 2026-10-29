function simplifyPath(path: string): string {
    const folders: string[] = path.split('/');
    const short: string[] = [];

    for (const folder of folders) {
        if (folder.length) {
            if (folder === ".") continue;
            if (folder === "..") { short.pop(); continue; }

            short.push(folder);
        }
    }

    return '/' + short.join('/');
};