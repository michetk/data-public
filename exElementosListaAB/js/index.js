var attrValueA, attrValueB;
attrValueA = 0;
$(document).ready(function(){
    $('a#add1').click(function(event){
        event.preventDefault();
        var vetAux = [];
        var qtdeItens = $('#lista_a li').length;
        if ($('#lista_a li.listaA').last().val() > 0) {
            attrValueA = $('#lista_a li.listaA').last().val();
        }
        if (qtdeItens == 0) {
            var li = $('<li></li>');
            li.attr('value', attrValueA+1);
            li.attr('class', 'listaA');
            li.html('A: ITEM ' + (attrValueA+1));
        }
        else {
            li = $('<li></li>');
            li.attr('value', attrValueA+1);
            li.attr('class', 'listaA');
            li.html('A: ITEM ' + (attrValueA+1));  
        }
        $('#lista_a').prepend(li);
        $('#lista_a li').each(function(index, item){
            vetAux.push(item);
        });
        vetAux.sort(function(a, b){
            return a.value - b.value;
        });
        $('#lista_a').prepend(vetAux);
        if ($('#lista_a li.listaB').length == 1 && $('#lista_a li.listaA').length >= 1) {
            var recebeA = $('#lista_a li.listaA');
            var recebeB = $('#lista_a li.listaB');
            $('#lista_a').prepend(recebeA);
            $('#lista_a').append(recebeB);
        }
        attrValueA = $('#lista_a li').last().val();
        console.log('VALUE A: ', attrValueA);
    });
    $('a#remove1').click(function(event){
        event.preventDefault();
        $('#lista_a li').last().remove();
        if ($('#lista_a li').length == 2) {
            var recebeA = $('#lista_a li.listaA');
            var recebeB = $('#lista_a li.listaB');
            $('#lista_a').prepend(recebeA);
            $('#lista_a').append(recebeB);
        }
        attrValueA = $('#lista_a li.listaA').last().val();
        if (attrValueA == undefined) {
            if ($('#lista_b li.listaA').last().val()) {
                attrValueA = $('#lista_b li.listaA').last().val();
            }
            else {
                attrValueA = 0;
            }
        }
        if ($('#lista_a li.listaB').last().val()) {
            attrValueB = $('#lista_a li.listaB').last().val();
        }
        else {
            attrValueB = 0;
        }
    });
    attrValueB = 0;
    $('a#add2').click(function(event){
        event.preventDefault();
        var vetAux = [];
        qtdeItens = $('#lista_b li').length;
        if ($('#lista_b li.listaB').last().val() > 0) {
            attrValueB = $('#lista_b li.listaB').last().val();
        }
        if (qtdeItens == 0) {
            li = $('<li></li>');
            li.attr('value', attrValueB+1);
            li.attr('class', 'listaB');
            li.html('B: ITEM ' + (attrValueB+1));
        }
        else {
            li = $('<li></li>');
            li.attr('value', attrValueB+1);
            li.attr('class', 'listaB');
            li.html('B: ITEM ' + (attrValueB+1));
        }
        $('#lista_b').append(li);
        $('#lista_b li').each(function(index, item){
            vetAux.push(item);
        });
        vetAux.sort(function(a, b){
            return a.value - b.value;
        });
        $('#lista_b').prepend(vetAux);
        if ($('#lista_b li').length == 2) {
            var recebeA = $('#lista_b li.listaA');
            var recebeB = $('#lista_b li.listaB');
            $('#lista_b').prepend(recebeA);
            $('#lista_b').append(recebeB);
        }
        attrValueB = $('#lista_b li').last().val();
        console.log('VALUE B: ', attrValueB);
        
        //Controle de posições

        var moveA = $('#lista_b li.listaA').last();
        var attrLista = $('#lista_b li.listaA').last().attr('class');
        var moveListaId = parseInt(moveA.attr('value'));
        var vet = [];
        if (attrLista == 'listaA') {
            $('#lista_b li.listaB').each(function(){
                if (parseInt($(this).attr('value')) >= moveListaId){
                    var removido = $(this).remove();
                    vet.push(removido);
                    $('#lista_b').append(moveA);
                    $('#lista_b').append(vet);
                }
                else{
                    $('#lista_b').append(moveA);
                    return;
                }
            });   
        }
    });
    $('a#remove2').click(function(event){
        event.preventDefault();
        $('#lista_b li').last().remove();
        if ($('#lista_b li').length == 2) {
            var recebeA = $('#lista_b li.listaA');
            var recebeB = $('#lista_b li.listaB');
            $('#lista_b').prepend(recebeA);
            $('#lista_b').append(recebeB);
        }
        attrValueB = $('#lista_b li').last().val();
        if (attrValueB == undefined) {
            if ($('#lista_a li.listaB').last().val()) {
                attrValueB = $('#lista_a li.listaB').last().val();
            }
            else {
                attrValueB = 0;
            }
        }
        if ($('#lista_b li.listaA').last().val()) {
            attrValueA = $('#lista_b li.listaA').last().val();
        }
        else {
            attrValueA = 0;
        }
        
    });
    $('a.right').click(function(event){
        event.preventDefault();
        attrValueB = $('#lista_a li.listaB').last().val();
        attrValueA = $('#lista_b li.listaA').last().val();
        var vetAux = [];
        var classLi = $('#lista_a li').first().attr('class');
        console.log('class: ', classLi);
        var move = $('#lista_a li').first();
        if (classLi == 'listaA') {
            $('#lista_b').prepend(move);
        }
        else {
            $('#lista_b').append(move);
        }
        $('#lista_b li').each(function(index, item){
            vetAux.push(item);
        });
        vetAux.sort(function(a, b){
            return a.value - b.value;
        });
        $('#lista_b').prepend(vetAux);
        if ($('#lista_b li').length == 2) {
            var recebeA = $('#lista_b li.listaA');
            var recebeB = $('#lista_b li.listaB');
            $('#lista_b').prepend(recebeA);
            $('#lista_b').append(recebeB);
        }
        if (attrValueA == undefined) {
            if ($('#lista_b li.listaA').last().val()) {
                attrValueA = $('#lista_b li.listaA').last().val();
            }
            else {
                attrValueA = 0;
            }
        }
        else {
            attrValueA = $('#lista_b li.listaA').last().val();
        }
        if ($('#lista_a li.listaB').last().val()) {
            attrValueB = $('#lista_a li.listaB').last().val();
        }
        else {
            attrValueB = 0;
        }
    });
    $('a.left').click(function(event){
        event.preventDefault();
        attrValueA = $('#lista_b li.listaA').last().val();
        attrValueB = $('#lista_a li.listaB').last().val();
        var vetAux = [];
        var classLi = $('#lista_b li').first().attr('class');
        var move = $('#lista_b li').first();
        if (classLi == 'listaB') {
            $('#lista_a').append(move);   
        }
        else {
            $('#lista_a').prepend(move);
        }
        $('#lista_a li').each(function(index, item){
            vetAux.push(item);
        });
        vetAux.sort(function(a, b){
            return a.value - b.value;
        });
        $('#lista_a').prepend(vetAux);
        if ($('#lista_a li').length == 2) {
            var recebeA = $('#lista_a li.listaA');
            var recebeB = $('#lista_a li.listaB');
            $('#lista_a').prepend(recebeA);
            $('#lista_a').append(recebeB);
        }
        if (attrValueB == undefined) {
            if ($('#lista_a li.listaB').last().val()) {
                attrValueB = $('#lista_a li.listaB').last().val();
            }
            else {
                attrValueB = 0;
            }
        }
        else{
            attrValueB = $('#lista_a li.listaB').last().val();
        }
        if ($('#lista_b li.listaA').last().val()) {
            attrValueA = $('#lista_b li.listaA').last().val();
        }
        else {
            attrValueA = 0;
        }
    });
    
});
$(document).on('click', '#lista_a li', function(){
    var vetAux = [];
    $(this).remove();
    $('#lista_a li').each(function(index, item){
        vetAux.push(item);
    });
    vetAux.sort(function(a, b){
        return a.value - b.value;
    });
    $('#lista_a').prepend(vetAux);
    if ($('#lista_a li').length == 2) {
        var recebeA = $('#lista_a li.listaA');
        var recebeB = $('#lista_a li.listaB');
        $('#lista_a').prepend(recebeA);
        $('#lista_a').append(recebeB);
    }
    attrValueA = $('#lista_a li.listaA').last().val();
    if (attrValueA == undefined) {
        if ($('#lista_b li.listaA').last().val()) {
            attrValueA = $('#lista_b li.listaA').last().val();
        }
        else {
            attrValueA = 0;
        }
    }
    if ($('#lista_a li.listaB').last().val()) {
        attrValueB = $('#lista_a li.listaB').last().val();
    }
    else {
        attrValueB = 0;
    }
});
$(document).on('click', '#lista_b li', function(){
    var vetAux = [];
    $(this).remove();
    $('#lista_b li').each(function(index, item){
        vetAux.push(item);
    });
    vetAux.sort(function(a, b){
        return a.value - b.value;
    });
    $('#lista_b').prepend(vetAux);
    if ($('#lista_b li').length == 2) {
        var recebeA = $('#lista_b li.listaA');
        var recebeB = $('#lista_b li.listaB');
        $('#lista_b').prepend(recebeA);
        $('#lista_b').append(recebeB);
    }
    attrValueB = $('#lista_b li.listaB').last().val();
    if (attrValueB == undefined) {
        if ($('#lista_a li.listaB').last().val()) {
            attrValueB = $('#lista_a li.listaB').last().val();
        }
        else {
            attrValueB = 0;
        }
    }
    if ($('#lista_b li.listaA').last().val()) {
        attrValueA = $('#lista_b li.listaA').last().val();
    }
    else {
        attrValueA = 0;
    }
});