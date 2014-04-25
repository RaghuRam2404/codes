$(function(){
    $('.star-rating a').click(function(){
        var _ul = $(this).parent().parent();
        var _frame = $(this).parent().parent().parent().parent();
        var postId = _ul.data('post-id');
        var rating = parseInt($(this).data('value'));
        if (rating > 0) {
            _frame.html("<span>Saving rating...</span>");
            $.ajax({
                type: "POST",
                url: ajax_var_2.url,
                data: "action=post-like&nonce=" + ajax_var_2.nonce + "&rating=" + rating + "&post_id=" + postId,
                success: function(response){
                    _frame.html("<span><i class='icon-star3'></i> Now rated " + response + " / 5</span>");
                }
            });
        }
        return false;
    });
});